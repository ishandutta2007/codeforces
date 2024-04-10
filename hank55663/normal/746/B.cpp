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
int main(){
    int n;
    scanf("%d",&n);
    char c[2005];
    scanf("%s",c);
    string ans;
    for(int i = 0;i<n;i++){
        if(i&1){
            if(n&1){
                ans=c[i]+ans;
            }
            else{
                ans=ans+c[i];
            }
        }
        else{
            if(n&1){
                ans=ans+c[i];
            }
            else{
                ans=c[i]+ans;
            }
        }
    }
    cout<<ans<<endl;
}
/*
4
8
2 2 4
3 1 3 5
1 2
2 1 5
4 2 6 4 7
2 5 8
2 8 5
2 7 6
 */