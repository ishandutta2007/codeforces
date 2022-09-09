#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 52 + 5;

int n;
int p[MAXN];

vector<vector<int> > ans;

void oper(const vector<int> &vec)
{
	if((int)vec.size() <= 1) return;
	ans.push_back(vec);
	
	static int q[MAXN];
	int sum = n;
	
	int cur = 0;
	for(int i=(int)vec.size()-1; i>=0; --i)
	{
		int x = vec[i];
		sum -= x;
		for(int j=1; j<=x; ++j)
			q[++cur] = p[sum+j];
	}
	
	for(int i=1; i<=n; ++i) p[i] = q[i];
}

int main(void)
{
	scanf("%d",&n);
	for(int i=1; i<=n; ++i) scanf("%d",&p[i]);
	
	int len = 0;
	bool flag = 1;
	
	for(int k=1; k<n; ++k)
	{
		int pos;
		for(int i=1; i<=n; ++i)
			if(p[i] == k){ pos = i; break;}
		
		vector<int> vec(len,1);
		
		if(flag) vec.push_back(pos - len);
		else vec.push_back(n-len+1 - pos);
		
		int sum = 0;
		for(int i=0; i<(int)vec.size(); ++i)
			sum += vec[i];
		if(n-sum) vec.push_back(n-sum);
		
		if(!flag) reverse(vec.begin(), vec.end());
		
		oper(vec);
		
		flag ^= 1;
		++len;
	}
	
	if(p[1] != 1) oper(vector<int>(n,1));
	
	printf("%d\n",(int)ans.size());
	for(int i=0; i<(int)ans.size(); ++i)
	{
		printf("%d ",(int)ans[i].size());
		for(int j=0; j<(int)ans[i].size(); ++j)
			printf("%d ",ans[i][j]);
		putchar('\n');
	}
	
//	for(int i=1; i<=n; ++i) printf("%d ",p[i]);
	return 0;
}