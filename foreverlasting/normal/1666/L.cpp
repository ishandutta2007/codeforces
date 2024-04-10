#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define gc getchar
#define LL long long
#define pii pair<int,int>
#define fr first
#define sc second
#define mp make_pair
const int mxn=1e6+10;
int n,m,S,cnt,ex[mxn],bl[mxn],fa[mxn];
pii a[mxn];
int t,h[mxn];
struct Edge
{
	int to,nxt;
}e[mxn];
vector<int> ans1,ans2,rev[10];
inline int rd(){
    int s=0,w=1,ch=gc();
    while(ch<'0'||ch>'9'){
        if(ch=='-')w=-1;
        ch=gc();
    }
    while(ch>='0'&&ch<='9')s=s*10+ch-'0',ch=gc();
    return s*w;
}
void add(int u,int v) {e[++t]=(Edge){v,h[u]};h[u]=t;}
void dfs(int u,int B)
{
	int v;bl[u]=B;
	for(int i=h[u];i;i=e[i].nxt)
		if(!bl[v=e[i].to]) fa[v]=u,dfs(v,B);
		else if(v!=S&&bl[v]!=B)
		{
			for(int x=v;x!=S;x=fa[x]) ans1.pb(x);ans1.pb(S);
			ans2.pb(v);
			for(int x=u;x!=S;x=fa[x]) ans2.pb(x);ans2.pb(S);
			reverse(ans1.begin(),ans1.end());
			reverse(ans2.begin(),ans2.end());
			puts("Possible");
			printf("%d\n",(int)ans1.size());
			for(auto x:ans1) printf("%d ",x);puts("");
			printf("%d\n",(int)ans2.size());
			for(auto x:ans2) printf("%d ",x);puts("");
			exit(0);
		}
//		else if(v==S&&!ex[B])
//		{
//			++cnt;ex[B]=1;
//			rev[cnt].pb(S);
//			for(int x=u;x!=S;x=fa[x]) rev[cnt].pb(x);rev[cnt].pb(S);
//			if(cnt==2)
//			{
//				ans1.swap(rev[1]);ans2.swap(rev[2]);
//				reverse(ans1.begin(),ans1.end());
//				reverse(ans2.begin(),ans2.end());
//				puts("Possible");
//				printf("%d\n",(int)ans1.size());
//				for(auto x:ans1) printf("%d ",x);puts("");
//				printf("%d\n",(int)ans2.size());
//				for(auto x:ans2) printf("%d ",x);puts("");
//				exit(0);
//			}
//		}
}
int main(){
    n=rd();m=rd();S=rd();bl[S]=-1;
    for(int x,y,i=1;i<=m;++i) a[i].fr=x=rd(),a[i].sc=y=rd(),add(x,y);
    for(int v,i=h[S];i;i=e[i].nxt)
    	if(!bl[v=e[i].to]) fa[v]=S,dfs(v,v);
    	else if(bl[v]!=v)
		{
			for(int x=v;x!=S;x=fa[x]) ans1.pb(x);ans1.pb(S);
			ans2.pb(v);ans2.pb(S);
			reverse(ans1.begin(),ans1.end());
			reverse(ans2.begin(),ans2.end());
			puts("Possible");
			printf("%d\n",(int)ans1.size());
			for(auto x:ans1) printf("%d ",x);puts("");
			printf("%d\n",(int)ans2.size());
			for(auto x:ans2) printf("%d ",x);puts("");
			exit(0);
		}
    puts("Impossible");
    return 0;
}