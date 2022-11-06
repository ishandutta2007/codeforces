#include<cstdio>
#include<cstring>
#include<algorithm>
#define rep(i,x,y) for(int i=(x);i<=(y);i++)
using namespace std;
struct qw{long long a;int b;}w[100002];
inline bool cmp(qw x,qw y){return ((x.a!=y.a)?(x.a<y.a):(x.b<y.b));}
int a[100001],p[26],s[26],n;
long long ans;char ch[100001];
int main(){
    rep(i,0,25)scanf("%d",&p[i]);
    scanf("%s",ch);n=strlen(ch);
    rep(i,1,n)a[i]=ch[i-1]-'a';
    rep(i,1,n){
        w[i].a=w[i-1].a+p[a[i]];w[i].b=i;
    }
    sort(w+1,w+n+1,cmp);w[n+1].a=26;
    rep(i,1,n){
        s[a[w[i].b]]++;
        if(w[i].b<n)ans+=s[a[w[i].b+1]];
        if(w[i].a!=w[i+1].a)rep(i,0,25)s[i]=0;
    }
    printf("%I64d\n",ans);
}