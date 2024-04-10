




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
#define pi acos(-1)
#define sqr(x) ((x)*(x))
#define pdd pair<double,double>
#define MEMS(x) memset(x,-1,sizeof(x))
#define MEM(x) memset(x,0,sizeof(x))
#define less Less
#define EPS 1e-4
#define arg ARG
#define cpdd const pdd
#define rank Rank
#define MXN 150
#define KK 500
#define N 100005
int main(){
    int n;
    scanf("%d",&n);
    char c1[200005],c2[200005];
    scanf("%s %s",c1,c2);
    vector<int> v1,v2;
    for(int i = 0;i<n;i++){
        if(c1[i]!=c2[i]){
            if(c1[i]=='a')v1.pb(i+1);
            else v2.pb(i+1);
        }
    }
    if((v1.size()+v2.size())%2){
        printf("%d\n",-1);
    }
    else{
        printf("%d\n",(v1.size()+1)/2+(v2.size()+1)/2);
        while(v1.size()>1){
            int a=v1.back();v1.pop_back();
            int b=v1.back();v1.pop_back();
            printf("%d %d\n",a,b);
        }
         while(v2.size()>1){
            int a=v2.back();v2.pop_back();
            int b=v2.back();v2.pop_back();
            printf("%d %d\n",a,b);
        }
        if(v1.size()&&v2.size()){
            printf("%d %d\n%d %d\n",v1.back(),v1.back(),v1.back(),v2.back());
        }
    }
    return 0;
}