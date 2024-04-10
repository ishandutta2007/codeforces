#include<bits/stdc++.h>
//#include<bits/extc++.h>
using namespace std;
//using namespace __gnu_pbds;
//typedef tree<double,null_type,less<double>,rb_tree_tag,tree_order_statistics_node_update> set_t;
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
typedef long long LL;
#define MXN 3000
int mod=998244353;
LL f_pow(LL a,LL b){
    LL res=1,temp=a;
    while(b){
        if(b&1)res=res*temp%mod;
        temp=temp*temp%mod;
        b>>=1;
    }
    return res;
}
int main(){
    int n,k;
    scanf("%d %d",&n,&k);
    vector<int> v1,v2;
    LL ans=1;
    for(int i = 0;i<n;i++){
        int x;
        scanf("%d",&x);
        if(i&1){
            if(v1.size()&&v1.back()==x&&x!=-1)ans=0;
            v1.pb(x);
        }
        else{
            if(v2.size()&&v2.back()==x&&x!=-1)ans=0;
            v2.pb(x);
        }
    }

    for(int t=0;t<2;t++){
        int left=-1,cnt=0;
        for(auto it:v1){
           // printf("%d\n",it);
            if(it==-1){
                cnt++;
            }
            else{
                if(cnt){
                    LL sum=1;
                    //if(left==-1)
                    //sum*=k,cnt--;
                    LL temp=cnt;
                    while(cnt--){
                        sum*=(k-1);
                        sum%=mod;
                    }
                    if(left==-1);
                    else{
                        if(left==it){
                            if(temp&1){
                                sum = (sum+1)*f_pow(k,mod-2)%mod*(k-1)%mod;
                            }
                            else{
                                sum = (sum-1)*f_pow(k,mod-2)%mod*(k-1)%mod;
                            }
                        }
                        else{
                            if(temp&1){
                                sum = (sum+1)*f_pow(k,mod-2)%mod*(k-1)%mod;
                                sum--;
                            }
                            else{
                                sum = (sum-1)*f_pow(k,mod-2)%mod*(k-1)%mod;
                                sum++;
                            }
                        }
                    }
                    ans*=sum;
                    ans%=mod;
                    cnt=0;
                }
                left=it;
            }
        }
        //printf("?\n");
        if(cnt){
            LL sum=1;
            if(left==-1)
            sum*=k,cnt--;
            while(cnt--){
                sum*=(k-1);
                sum%=mod;
            }
            ans*=sum;
            ans%=mod;
        }
       // printf("ans:%lld\n",ans);
        swap(v1,v2);
    }
    printf("%lld\n",ans);
}