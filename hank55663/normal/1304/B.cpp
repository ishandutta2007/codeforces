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
#define MXN 100005

int main(){
    int n,M;
    scanf("%d %d",&n,&M);
    map<string,int> m;
    for(int i = 0;i<n;i++){
        string str;
        cin>>str;
        m[str]++;
    }
    vector<string> v;
    string mid="";
    for(auto& it:m){
        string str=it.x;
        reverse(str.begin(),str.end());
        if(str==it.x){
            while(it.y>1){
                it.y-=2;
                v.pb(str);
            }
            if(it.y){
                mid=str;
            }
        }
        else
        while(m[str]>0&&it.y>0){
            m[str]--;
            it.y--;
            v.pb(str);
        }
    }
    printf("%d\n",M*v.size()*2+mid.length());
    for(auto it:v){
        cout<<it;
    }
    reverse(v.begin(),v.end());
    cout<<mid;
    for(auto it:v){
        reverse(it.begin(),it.end());
        cout<<it;
    }
    printf("\n");
}
/*
6 10
1 1 0 0 0 0 0 0 0 0 
1 1 1 1 0 0 0 0 0 0 
0 0 1 1 0 0 0 0 0 0 
2 2 3 3 0 0 0 0 0 0 
0 0 3 3 4 4 0 0 0 0 

{1}
{1}
{1000000000}
{1000000000}
1

1000000000 
1000
{1000}
{1000000000}
*/