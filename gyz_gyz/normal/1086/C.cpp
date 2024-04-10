#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=(x);i<=(y);++i)
#define dep(i,x,y) for(int i=(x);i>=(y);--i)
#define add(x,y) x=(x+(y))%mo
#define sqr(x) ((x)*(x))
#define pb push_back
#define fr first
#define sc second
#define clz __builtin_clz
#define N 2000000
#define mo 1000000007
#define eps 1e-8
#define inf 1000000000
#define Inf 2000000000000000000ll
using namespace std;
typedef long long ll;
char s[N],a[N],b[N];int n,k;
char p[300],q[300],r[300],t[300];
void prt(){
	printf("YES\n");
	rep(i,'a',k){
		if(!r[i])rep(j,'a',k)if(!t[j]){
			r[i]=j;t[j]=i;break;
		}
		printf("%c",r[i]);
	}printf("\n");
}
void cg(){
	rep(i,'a',k)r[i]=p[i],t[i]=q[i];
}
bool tr1(int i0){cg();
	rep(i,i0,n)if(r[s[i]]){
		if(r[s[i]]>a[i]){prt();return 1;}
		if(r[s[i]]<a[i])return 0;
	}else{
		rep(j,a[i]+1,k)if(!t[j]){
			r[s[i]]=j;t[j]=s[i];prt();return 1;
		}
		if(t[a[i]])return 0;
		r[s[i]]=a[i];t[a[i]]=s[i];
	}
	prt();return 1;
}
bool tr2(int i0){cg();
	rep(i,i0,n)if(r[s[i]]){
		if(r[s[i]]<b[i]){prt();return 1;}
		if(r[s[i]]>b[i])return 0;
	}else{
		rep(j,'a',b[i]-1)if(!t[j]){
			r[s[i]]=j;t[j]=s[i];prt();return 1;
		}
		if(t[b[i]])return 0;
		r[s[i]]=b[i];t[b[i]]=s[i];
	}
	prt();return 1;
}
void sol(){
	scanf("%d",&k);k+='a'-1;
	rep(i,'a',k)p[i]=q[i]=0;
	scanf("%s",s);scanf("%s",a);scanf("%s",b);n=strlen(a)-1;
	rep(i,0,n)if(p[s[i]]){
		if(p[s[i]]<a[i]||p[s[i]]>b[i]){printf("NO\n");return;}
		if(p[s[i]]>a[i]&&p[s[i]]<b[i]){cg();prt();return;}
		if(p[s[i]]==a[i]&&a[i]<b[i]){
			if(!tr1(i+1))printf("NO\n");return;
		}
		if(p[s[i]]==b[i]&&a[i]<b[i]){
			if(!tr2(i+1))printf("NO\n");return;
		}
	}else if(a[i]<b[i]){
		if(!q[a[i]]){
			q[a[i]]=s[i];p[s[i]]=a[i];if(tr1(i+1))return;
			q[a[i]]=p[s[i]]=0;
		}		
		rep(j,a[i]+1,b[i]-1){
			if(!q[j]){
				q[j]=s[i],p[s[i]]=j;
				cg();prt();return;
			}
		}
		if(!q[b[i]]){
			q[b[i]]=s[i];p[s[i]]=b[i];if(tr2(i+1))return;
		}
		printf("NO\n");return;
	}else{
		if(q[a[i]]){
			printf("NO\n");return;
		}else q[a[i]]=s[i],p[s[i]]=a[i];
	}
	cg();prt();
}
int main(){int T;
	scanf("%d",&T);
	rep(i,1,T)sol();
}