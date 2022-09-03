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
#define EPS 1e-4
#define arg ARG
#define cpdd const pdd
#define rank Rank
#define MXN 205
int isprime[2000005];
void Find(){
    fill(isprime+2,isprime+2000005,1);
    for(int i = 2;i<2000005;i++){
        if(isprime[i]){
            for(int j=i*2;j<2000005;j+=i){
                isprime[j] = 0;
            }
        }
    }
}
int main(){
    int n;
    scanf("%d",&n);
    int a[1005];
    for(int i = 0;i<n;i++){
        scanf("%d",&a[i]);
    }
    Find();
    vector<int> ans{a[0]};
    int one=0,another=-1;
    for(int i = 0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(isprime[a[i]+a[j]]){
                ans=vector<int>{a[i],a[j]};
            }
        }
        if(a[i]==1)one++;
        else if(isprime[a[i]+1])another=a[i];
    }
    if(one){
        int num=one;
        if(another!=-1)num++;
        if(num>ans.size()){
            ans.clear();
            for(int i = 0;i<one;i++)ans.pb(1);
            if(another!=-1)ans.pb(another);
        }
    }
    printf("%d\n",ans.size());
    for(auto it:ans){
        printf("%d ",it);
    }
    printf("\n");
    
}
/*
0
10
20
30
40

4+3+3+4+3+2+2+1
13:00
11:

11:24
11:48
12:12
12:36
13:00
13:24
13:48
14:12
14:36
*/