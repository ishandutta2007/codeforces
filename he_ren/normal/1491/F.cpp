#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

inline int ask(const vector<int> &l,const vector<int> &r)
{
	printf("? %d %d\n",(int)l.size(),(int)r.size());
	for(int i=0; i<(int)l.size(); ++i) printf("%d ",l[i]); putchar('\n');
	for(int i=0; i<(int)r.size(); ++i) printf("%d ",r[i]); putchar('\n');
	fflush(stdout);
	int res;
	scanf("%d",&res);
	return res;
}

inline vector<int> at(int l,int r)
{
	vector<int> res(r-l+1);
	for(int i=l; i<=r; ++i) res[i-l] = i;
	return res;
}
inline vector<int> at(int pos){ return vector<int>(1,pos);}

void solve(void)
{
	int n;
	scanf("%d",&n);
	
	int pos;
	for(int i=2; i<=n; ++i)
		if(ask(at(1,i-1), at(i))){ pos = i; break;}
	
	vector<int> ans;
	for(int i=pos+1; i<=n; ++i)
		if(ask(at(pos), at(i)) == 0)
			ans.push_back(i);
	
	int l = 1, r = pos-1;
	while(l<r)
	{
		int mid = (l+r)>>1;
		if(ask(at(1,mid), at(pos))) r = mid;
		else l = mid+1;
	}
	
	for(int i=1; i<pos; ++i)
		if(i != l) ans.push_back(i);
	
	printf("! %d ",(int)ans.size());
	for(int i=0; i<(int)ans.size(); ++i) printf("%d ",ans[i]);
	putchar('\n');
	fflush(stdout);
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}