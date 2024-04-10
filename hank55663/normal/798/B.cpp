#include<bits/stdc++.h>
#define pii pair<int,int>
#define pb(x) push_back(x)
#define sqr(x) ((x)*(x))
#define mp(x,y) make_pair((x),(y))
#define N 1000005
#define x first 
#define y second
typedef long long LL;
using namespace std;
int main(){
	int n;
	string s;
	scanf("%d",&n);
	map<string,int> m[100];
	int len=0;
	int allsame=1;
	char c;
	for(int i=0;i<n;i++){
		cin>>s;
		len=s.size();
		s=s+s;
		for(int j=0;j<len;j++){
			if(m[i].find(s.substr(j,len))==m[i].end())
			m[i][s.substr(j,len)]=j;
		}
	}
	int ans=1e9;
	for(map<string,int>::iterator it=m[0].begin();it!=m[0].end();it++){
		int sum=it->y;
		for(int i=1;i<n;i++){
			if(m[i].find(it->x)==m[i].end()){
				printf("-1\n");
				return 0;
			}
			sum+=m[i][it->x];
		}	
		ans=min(ans,sum);
	}
	printf("%d\n",ans);
}