#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define ULL unsigned long long
#define mp make_pair
#define pb push_back
#define pii pair<int,int>
#define pll pair<LL,LL>
#define x first
#define y second
#define pi acosl(-1)
#define sqr(x) ((x)*(x))
#define pdd pair<double,double>
#define MEMS(x) memset(x,-1,sizeof(x))
#define MEM(x) memset(x,0,sizeof(x))
//#define less Less
#define EPS 1e-4
#define arg ARG
#define cpdd const pdd
#define ld long double
//#define N 6000005
#define rank Rank
#define index Index
#define MXN 1005
#define N 2000005
void z_alg1(char *s,int len,int *z){
	int l=0,r=0;
	z[0]=len;
	for(int i=1;i<len;++i){
		z[i]=r>i?min(r-i+1,z[z[l]-(r-i+1)]):0;
		while(i+z[i]<len&&s[z[i]]==s[i+z[i]])++z[i];
		if(i+z[i]-1>r)r=i+z[i]-1,l=i;
	}
}
char c1[500005],c2[500005];
char c3[1000005];
int l[500005],r[500005];
char c[2000005];
int res[2000005];
void build(int *l,char *s,char *t,int n,int m){

    int now=0;
    for(int i=0;t[i]!=0;i++){
        c[now++]=t[i];
    }
    c[now++]='$';
    for(int i = 0;s[i]!=0;i++){
        c[now++]=s[i];
    }
    z_alg1(c,now,res);
    for(int i=m+1;i<=n+m;i++){
        l[i-m-1]=res[i];
    }
}
LL S[1000005],cnt[1000005];
void add(int x,int k,LL *s){
   // printf("%d %d\n",x,k);
    for(int i = x;i<1000005;i+=i&-i){
        s[i]+=k;
    }
}
LL query(int x,LL *s){
    if(x<0)return 0;
    LL res=0;
    for(int i = x;i>0;i-=i&-i){
        res+=s[i];
    }
    return res;
}
int main(){
    int n,m;
    scanf("%d %d",&n,&m);
    scanf("%s %s %s",c1,c2,c3);
    build(l,c1,c3,n,m);
    for(int i = 0;i<n;i++){
        if(l[i]==m)l[i]--;
      //  printf("%d ",l[i]);
    }
 //  printf("\n");
    reverse(c3,c3+m);
    reverse(c2,c2+n);
    build(r,c2,c3,n,m);
    reverse(r,r+n);
    for(int i = 0;i<n;i++){
        if(r[i]==m)r[i]--;
      // printf("%d ",r[i]);
    }
  // printf("\n");

    for(int i = 0;i<n&&i<m-1;i++){
        if(r[i])
        add(r[i],1,cnt),add(r[i],r[i],S);
    }
    LL res=0;
    for(int i =0;i<n;i++){
        if(l[i]){
           // printf("!\n");
            LL mcnt=query(m,cnt)-query(m-l[i]-1,cnt);
            LL mval=query(m,S)-query(m-l[i]-1,S);
            assert(mcnt>=0&&mval>=0);
         //   printf("!!\n");
            res+=mval+mcnt*l[i]-(m-1)*mcnt;
         //   printf("%lld %lld %lld %lld\n",m-l[i],mcnt,mval,res);
        }
        if(r[i]){
        add(r[i],-1,cnt);
        add(r[i],-r[i],S);
        }
        if(i+m-1<n){
            if(r[i+m-1]){
                add(r[i+m-1],1,cnt);
                add(r[i+m-1],r[i+m-1],S);
            }
        }
    }
    printf("%lld\n",res);
    return 0;
}