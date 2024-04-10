#include<bits/stdc++.h>
using namespace std;
#define LL long long
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
#define N 200005
#define less Less
int main(){
    int k;
    scanf("%d\n",&k);
    char c;
    vector<int> v;
    int cnt=0;
    while(scanf("%c",&c)){
        if(c!='\n')
        cnt++;
        if(c=='-'||c==' '||c=='\n'){
            v.pb(cnt);
            cnt=0;
        }
        if(c=='\n')
        break;
    }
   // v.pb(cnt);
    int Max=1e6,Min=0;
    while(Max>Min+1){
        int mid=(Max+Min)/2;
        int tot=1;
        int now=0;
        for(auto it:v){
            if(now+it<=mid);
            else{
                tot++;
                now=0;
                if(it>mid){
                    tot+=1e7;
                    break;
                }
            }
            now+=it;
        }
        if(tot>k){
            Min=mid;
        }
        else{
            Max=mid;
        }
    }
    printf("%d\n",Max);
}