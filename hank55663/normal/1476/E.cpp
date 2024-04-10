#include<bits/stdc++.h>
#define pb push_back
#define x first
#define y second
#define pdd pair<double,double>
#define pii pair<int,int>
#define pll pair<LL,LL>
#define mp make_pair
#define LL long long
#define ULL unsigned long long
#define sqr(x) ((x)*(x))
#define pi acosl(-1)
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
using namespace std;
vector<int> v[100005];
int degree[100005];
bool solve(){
	int n,m,k;
	map<string,int> loc;
	scanf("%d %d %d",&n,&m,&k);
	for(int i=1;i<=n;i++){
		char c[10];
		scanf("%s",c);
		loc[string(c)]=i;
	}
	for(int i = 1;i<=m;i++){
		char c[10];
		scanf("%s",c);
		int x;
		scanf("%d",&x);
		string s(c);
		int ok=0;
		for(int j=0;j<(1<<k);j++){
			string tmp=s;
			for(int a=0;a<k;a++){
				if(j&(1<<a)){
					tmp[a]='_';
				}
			}
			if(loc.find(tmp)!=loc.end()){
				if(loc[tmp]==x)ok=1;
				else v[x].pb(loc[tmp]),degree[loc[tmp]]++;
			}
		//	cout<<tmp<<endl;
		}
		if(!ok){
			printf("NO\n");
			return true;
		}
	}
	queue<int> q;
	vector<int> ans;
	for(int i = 1;i<=n;i++){
		if(degree[i]==0)q.push(i);
	}
	while(!q.empty()){
		int x=q.front();
		q.pop();
		ans.pb(x);
		for(auto it:v[x]){
			if(--degree[it]==0)q.push(it);
		}
	}
	if(ans.size()==n){
		printf("YES\n");
		for(auto it:ans)printf("%d ",it);
		printf("\n");
	}
	else{
		printf("NO\n");
	}
	return true;
}
int main(){
    int t=1;//00000;
   // scanf("%d",&t);
    while(t--)solve();
}
/*
1 4 10100
1 6 1010100
1 8 101010100
1 y 10100  (y+1)  y/2
2 5 1100100
2 6 11001100
2 7 110011000
2 8 1100110000
2 9 11001100100
*/