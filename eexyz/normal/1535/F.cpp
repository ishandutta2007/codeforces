#pragma GCC optimize(3)
#pragma GCC target("avx,sse2,sse3,sse4,mmx")
#pragma GCC optimize("Ofast") 
#pragma GCC optimize("inline")
#pragma GCC optimize("-fgcse")
#pragma GCC optimize("-fgcse-lm")
#pragma GCC optimize("-fipa-sra")
#pragma GCC optimize("-ftree-pre")
#pragma GCC optimize("-ftree-vrp")
#pragma GCC optimize("-fpeephole2")
#pragma GCC optimize("-ffast-math")
#pragma GCC optimize("-fsched-spec")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("-falign-jumps")
#pragma GCC optimize("-falign-loops")
#pragma GCC optimize("-falign-labels")
#pragma GCC optimize("-fdevirtualize")
#pragma GCC optimize("-fcaller-saves")
#pragma GCC optimize("-fcrossjumping")
#pragma GCC optimize("-fthread-jumps")
#pragma GCC optimize("-funroll-loops")
#pragma GCC optimize("-fwhole-program")
#pragma GCC optimize("-freorder-blocks")
#pragma GCC optimize("-fschedule-insns")
#pragma GCC optimize("inline-functions")
#pragma GCC optimize("-ftree-tail-merge")
#pragma GCC optimize("-fschedule-insns2")
#pragma GCC optimize("-fstrict-aliasing")
#pragma GCC optimize("-fstrict-overflow")
#pragma GCC optimize("-falign-functions")
#pragma GCC optimize("-fcse-skip-blocks")
#pragma GCC optimize("-fcse-follow-jumps")
#pragma GCC optimize("-fsched-interblock")
#pragma GCC optimize("-fpartial-inlining")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("-freorder-functions")
#pragma GCC optimize("-findirect-inlining")
#pragma GCC optimize("-fhoist-adjacent-loads")
#pragma GCC optimize("-frerun-cse-after-loop")
#pragma GCC optimize("inline-small-functions")
#pragma GCC optimize("-finline-small-functions")
#pragma GCC optimize("-ftree-switch-conversion")
#pragma GCC optimize("-foptimize-sibling-calls")
#pragma GCC optimize("-fexpensive-optimizations")
#pragma GCC optimize("-funsafe-loop-optimizations")
#pragma GCC optimize("inline-functions-called-once")
#pragma GCC optimize("-fdelete-null-pointer-checks")
#include<bits/stdc++.h>
using namespace std;
#define pf push_front
#define pb push_back
#define N 200005
#define ls k<<1
#define rs k<<1|1
#define mid (l+r>>1)
#define ll long long
#define ull unsigned long long
ll M,M_,mm[25]={10000019,10000079,10006987,10007159,10000103,1000000007,1000000009,998244353,1145141923,10007341,10000481,10000987,10000993,10001207,10001237,10001363,10001567,10001533,10001617,99999113,99999089,99998929,99998551,99998377,99998413};
char s[N];
ull U,V,hs[1005],cf[1004];
vector<char>u[N];
int n,L,i,l,f1,f2,j,k,fl;
ll ans;
struct node{int c[26],ps;}a[N];
inline bool cmp(node aa,node bb){
	for(int i=0;i<26;++i)if(aa.c[i]!=bb.c[i])return aa.c[i]<bb.c[i];
	return 0;
}
void sol1(int l,int r){
	int ii,jj,i,j;
	for(ii=l+1;ii<=r;++ii){
		i=a[ii].ps;
		for(jj=l;jj<ii;++jj){
			f1=fl=0;j=a[jj].ps;
			for(k=1;k<=L;++k){
				if(u[i][k]!=u[j][k]){if(!f1)f1=k;f2=k;}
			}
			for(k=f1+1;k<=f2;++k)if(u[i][k]<u[i][k-1])fl=1;
			if(fl){
				for(k=f1+1;k<=f2;++k){
					if(u[j][k]<u[j][k-1])fl=0;
				}
				if(!fl)++ans;
			}
		}
	}
}
unordered_map<ull,int>p;
int las,c,len,x,y;
int main(){
//	freopen("a.txt","r",stdin);
	scanf("%d",&n);
	for(i=1;i<=n;++i){
		scanf("%s",s+1);
		l=strlen(s+1);u[i].pb(0);
		for(j=1;j<=l;++j)++a[i].c[s[j]-'a'],a[i].ps=i,u[i].pb(s[j]);
	}L=l;
	if(n<=4000){
		ans=1ll*n*(n-1)/2*1337;
		sort(a+1,a+n+1,cmp);
		for(i=las=1;i<=n;++i){
			for(fl=j=0;j<26;++j)fl|=a[i].c[j]!=a[i+1].c[j];
			if(fl){
				len=i-las+1;
				ans-=1ll*len*(len-1)/2*1337;
				ans+=1ll*len*(len-1)>>1;
				sol1(las,i);
				las=i+1;
			}
		}
		cout<<ans; 
		return 0;
	}
	else{
		srand(time(NULL));
		int xxx=rand()%25,yyy;
		M=mm[xxx];
		yyy=rand()%25;while(yyy==xxx)yyy=rand()%25;
		M_=mm[yyy];
		sort(a+1,a+n+1,cmp);
		ans=1ll*n*(n-1)/2*1337;
		for(i=cf[0]=1;i<=1000;++i)cf[i]=cf[i-1]*M;
		for(i=las=1;i<=n;++i){
			for(fl=j=0;j<26;++j)fl|=a[i].c[j]!=a[i+1].c[j];
			if(fl){
				len=i-las+1;p.clear();
				ans-=1ll*len*(len-1)/2*1337;
				ans+=1ll*len*(len-1);
				for(j=las;j<=i;++j){
					for(x=1;x<=l;++x)
						hs[x]=hs[x-1]*M+u[a[j].ps][x];
					for(x=0;x<l;++x){
						U=hs[x];
						for(y=x+2;y<=l;++y){
							V=hs[l]-hs[y]*cf[l-y]; 
							++p[U+V*M_];
						}
					}
				}
				for(j=las;j<=i;++j){
					for(x=1;x<=l;++x)
						hs[x]=hs[x-1]*M+u[a[j].ps][x];
					for(x=1;x<=l;x=y+1){
						y=x;
						while(y<l&&u[a[j].ps][y]<=u[a[j].ps][y+1])++y;
						U=hs[x-1];
						if(y>=x+1){
							V=hs[l]-hs[y]*cf[l-y]; 
							ans-=p[U+V*M_]-1;
						}
					}
				}
				las=i+1;
			}
		}
		cout<<ans;
	}
}