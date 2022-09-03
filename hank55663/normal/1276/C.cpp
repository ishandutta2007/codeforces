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
int S[400005];
void add(int x,int k){
    for(int i = x ; i < 400005 ; i += i & -i){
        S[i]+=k;
    }
}
int query(int x){
    int res = 0;
    for(int i = x ; i > 0 ; i -= i & -i){
        res += S[i];
    }
    return res;
}
int main(){
    int n;
    scanf("%d",&n);
    map<int,int> m;
    for(int i = 0 ; i < n ; i++){
        int x;
        scanf("%d",&x);
        m[x]++;
    }
    for(auto it : m){
        add(1, 1);
        add(it.y+1,-1);
    }
    int tot = 0;
    int ans = 0, ansi;
    for(int i = 1 ; i <= n ; i++){
        tot += query(i);
        if(tot / i < i) break;
        int res = tot / i * i;
        if(res > ans){
            ans = res;
            ansi = i;
        }
    }
    printf("%d\n",ans);
    printf("%d %d\n",ansi,ans/ansi);
    vector<pii> res;
    for(auto it : m){
        for(int j = 0 ; j < min(it.y, ansi) ; j++)
            res.pb(mp(it.y,it.x));
    }
    sort(res.begin(),res.end());
    vector<vector<int> > matrix(ansi);
    for(int i = 0 ; i < ans/ansi ; i++){
        for(int j = 0 ; j < ansi ; j++){
            matrix[j].pb(res.back().y);
            res.pop_back();
        }
    }
    reverse(matrix.begin(),matrix.end());
    for(int i = 0 ; i < ansi ; i++){
        int m = ans/ansi;
       // sort(matrix[i].begin(),matrix[i].end());
        for(int j = 0 ; j < ans/ansi ; j++){
            printf("%d ",matrix[i][(j+i)%m]);
        }
        printf("\n");
    }
    //int cnt[400005];

}
/*
7 8
1 3 1
2 3 9
2 4 3
2 5 4
4 5 7
3 6 6
3 7 7
6 7 8

*/