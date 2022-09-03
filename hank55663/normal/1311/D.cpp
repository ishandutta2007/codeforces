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
vector<int> v[100005];
int main(){
    int t;
    scanf("%d",&t);
    for(int i = 1;i<100005;i++){
        for(int j=i;j<100005;j+=i){
            v[j].pb(i);
        }
    }
    while(t--){
        int a,b,c;
        scanf("%d %d %d",&a,&b,&c);
        int ans=1e9;
        int aa,bb,cc;
        for(int i = max(b-20000,1);i<=b+20000;i++){
            int sum=abs(b-i);
            auto it=lower_bound(v[i].begin(),v[i].end(),a);
            int aaa;
            if(it==v[i].end()){
                aaa=*(it-1);
                sum+=abs(aaa-a);
            }
            else if(it==v[i].begin()){
                aaa=*it;
                sum+=abs(aaa-a);
            }
            else{
                if(*it-a<a-*(it-1)){
                    aaa=*it;
                    sum+=*it-a;
                }
                else{
                    aaa=*(it-1);
                    sum+=a-*(it-1);
                }
            }
            int ccc;
            if(c<=i){
                ccc=i;
            }
            else{
                if(c%i<i-c%i){
                    ccc=c/i*i;
                }
                else{
                    ccc=(c/i+1)*i;
                }
            }
            sum+=abs(ccc-c);
            if(sum<ans){
                ans=sum;
                aa=aaa;
                bb=i;
                cc=ccc;
            }
        }
        printf("%d\n%d %d %d\n",ans,aa,bb,cc);
    }
}