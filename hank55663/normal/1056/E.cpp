#include<bits/stdc++.h>
#define LL long long 
#define pll pair<LL,LL>
#define pii pair<int,int> 
#define pdd pair<double,double>
#define cpdd const pdd
#define pb push_back
#define sqr(x) ((x)*(x))
#define mp make_pair
#define x first
#define y second
#define MEMS(x) memset(x,-1,sizeof(x))
#define MEM(x) memset(x,0,sizeof(x))
using namespace std;
#define search Search
#define index Index
#define transform Transform
#define IOS ios_base::sync_with_stdio(0); cin.tie(0)
#define Line pll
#define hash myhash
int mod;
int mod2;
int mod10[10]={1097774749,1076767633,100102021,999997771,1001010013,1000512343,987654361,999991231,999888733,987777733};
LL hash[1000005];
LL hash2[1000005];
LL base=400;
LL base2=123;
LL Base[1000005];
LL Base2[1000005];
void Hash(char *c){
    hash[0]=0;
    hash2[0]=0;
    for(int i=1;c[i]!=0;i++){
        hash[i]=hash[i-1]*base;
        hash[i]+=c[i]-'a';
        hash[i]%=mod;
        hash2[i]=hash2[i-1]*base2;
        hash2[i]+=c[i]-'a';
        hash2[i]%=mod2;
      //  printf("%lld ",hash[i]);
    }
  //  printf("\n");
    Base[0]=1;
    Base2[0]=1;
    for(int i=1;c[i]!=0;i++){
        Base[i]=Base[i-1]*base%mod;
        Base2[i]=Base2[i-1]*base2%mod2;
    }
}
pll gethash(int l,int r){
    pll p= mp( ((hash[r]-hash[l-1]*Base[r-l+1]%mod)%mod+mod)%mod,
                ((hash2[r]-hash2[l-1]*Base2[r-l+1]%mod2)%mod2+mod2)%mod2);
    return p;
}
int main(){
    srand(time(NULL));
    int x=rand()%10;
    mod=mod10[x];//rand()%10];
    //printf("%d\n",mod);
    mod2=mod10[(x+1)%10];
    char s[100005];
    scanf("%s",s);
    char t[1000005];
    scanf("%s",t+1);
    Hash(t);
   /** for(int i=1;t[i]!=0;i++)
        for(int j=i;t[j]!=0;j++)
            printf("%d %d %d\n",i,j,gethash(i,j).x);*/
    int z=0,o=0;
    for(int i=0;s[i]!=0;i++){
        if(s[i]=='0')
        z++;
        else
        o++;
    }
    if(z<o){
        swap(z,o);
        for(int i=0;s[i]!=0;i++){
            if(s[i]=='0')s[i]='1';
            else s[i]='0';
        }
    }
    int len=strlen(t+1);
    int ans=0;
    for(int i=1;z*i<len;i++){
        int a=i,b=(len-z*i);
        if(b%o!=0)
        continue;
        b/=o;
        pll hash1,hash2;
        int now=0;
        for(int j=0;s[j];j++){
            if(s[j]=='0'){
                hash1=gethash(now+1,now+a);
           //     printf("%d %d %d %d ",now+1,now+a,hash1.x,hash1.y);
                now+=a;
            }
            if(s[j]=='1'){
                hash2=gethash(now+1,now+b);
               // printf("%d %d ",hash2.x,hash2.y);
                now+=b;
            }
        }
       // printf("%d %d\n",a,b);
        int ok=1;
        now=0;
        for(int j=0;s[j];j++){
            if(s[j]=='0'){
                if(hash1!=gethash(now+1,now+a))ok=0;
                now+=a;
            }
            if(s[j]=='1'){
                if(hash2!=gethash(now+1,now+b))ok=0;
                now+=b;
            }
        }
        if(hash1==hash2&&a==b)ok=0;
       // if(ok)printf("%d %d\n",a,b);
        ans+=ok;
    }
    printf("%d\n",ans);
}