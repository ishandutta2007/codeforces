#include<bits/stdc++.h>
//#include<bits/extc++.h>
using namespace std;
//using namespace __gnu_pbds;
//typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> set_t;
#define mp(a,b) make_pair((a),(b))
#define pii pair<int,int>
#define pll pair<LL,LL>
#define pdd pair<double,double>
#define pb push_back
#define x first
#define y second
#define sqr(x) ((x)*(x))
#define EPS 1e-6
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
#define pi acos(-1)
#define index Index
#define Line pll
#define hash Hash
inline void manacher(int *s,int len,int *z){
	int l=0,r=0;
	for(int i=1;i<len;++i){
		z[i]=r>i?min(z[2*l-i],r-i):1;
		while(s[i+z[i]]==s[i-z[i]])++z[i];
		if(z[i]+i>r)r=z[i]+i,l=i;
	}
}
typedef long long LL;
int hash[255][255][255];
int mod=1001010013;
int base=16534;
LL ba[26];
int main(){
    int n,m;
    ba[0]=1;
    for(int i=1;i<26;i++){
        ba[i]=ba[i-1]*base%mod;
    }
    char c[255][255];
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%s",c[i]);
    }
    int now=-1;
    for(int i=1;i<=n;i++){
        for(int j=0;j<m;j++){
            int cnt[26];
            MEM(cnt);
            int tot=0;
            LL value=0;
            for(int k=j;k<m;k++){
                value=(value+ba[c[i][k]-'a'])%mod;
                cnt[c[i][k]-'a']++;
                if(cnt[c[i][k]-'a']&1)
                tot++;
                else
                tot--;
                hash[i][j][k]=value;
                if(tot>1){
                    hash[i][j][k]=now;
                    now--;
                }
            }
        }
    }
   // printf("?\n");
    LL ans=0;
    for(int l=0;l<m;l++){
        for(int r=l;r<m;r++){
            int a[550];
            fill(a,a+550,-1e9-2);
            a[0]=-1e9-1;
            for(int i=1;i<=n;i++){
                a[i*2-1]=-1e9;
                a[i*2]=hash[i][l][r];
                a[i*2+1]=-1e9;
            }
           /* for(int i=0;i<=2*n+1;i++)
            printf("%d ",a[i]);*/
            int z[550];
            manacher(a,n*2+2,z);
          /*  printf("\n");
            for(int i=0;i<=2*n+1;i++)
            printf("%d ",z[i]);
            printf("\n");*/
            for(int i=1;i<=2*n;i++){
                if(i%2==1)
                ans+=z[i]/2;
                else{
                    if(hash[i/2][l][r]>=0)
                    ans+=z[i]/2;
                }
            }
        //    printf("%d %d %d\n",l,r,ans);
        }
    }
    printf("%lld\n",ans);
}
/*
1000000000 1000000000
1 1 1000000000 1000000000
1 1 1000000000 1000000000

*/