#include<bits/stdc++.h>
#define pb push_back
#define x first
#define y second
#define pdd pair<double,double>
#define pii pair<int,int>
#define pll pair<LL,LL>
#define mp make_pair
#define LL long long
#define ULL unsigned long long
#define sqr(x) ((x)*(x))
#define pi acosl(-1)
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
using namespace std;
#define Point pdd
#define Polygon vector<Point>
#define Line pair<Point,Point>
#define N 1000000
bool solve(){
    int n;
    scanf("%d",&n);
    vector<int> v;
    for(int i = 0;i<n;i++){
        int x;
        scanf("%d",&x);
        v.pb(x);
    }
    sort(v.begin(),v.end());
    reverse(v.begin(),v.end());
    LL ans1=0,ans2=0;
    for(int i = 0;i<v.size();i++){
        if(i%2==0){
            if(v[i]%2==0)ans1+=v[i];
        }
        else{
            if(v[i]%2==1)ans2+=v[i];
        }
    }
    if(ans1>ans2)printf("Alice\n");
    else if(ans1==ans2)printf("Tie\n");
    else printf("Bob\n");
    return true;
}
int main(){
    int t=1;00000;
    scanf("%d",&t);
    while(t--)solve();
}
/*
1 4 10100
1 6 1010100
1 8 101010100
1 y 10100  (y+1)  y/2
2 5 1100100
2 6 11001100
2 7 110011000
2 8 1100110000
2 9 11001100100
*/