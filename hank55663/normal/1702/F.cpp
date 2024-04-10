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
#define double long double
using namespace std;
void solve(){  
    multiset<int> b,a;
    int n;
    scanf("%d",&n);
    for(int i = 1;i<=n;i++){
        int x;
        scanf("%d",&x);
        a.insert(x);
    }
    for(int i = 1;i<=n;i++){
        int x;
        scanf("%d",&x);
        b.insert(x);
    }
    while(a.size()){
        while(*b.rbegin()>*a.rbegin()){
            int x=*b.rbegin();
            b.erase(b.find(x));
            b.insert(x/2);
        }
        if(b.find(*a.rbegin())==b.end()){
            int x=*a.rbegin();
            if(x&1){
                printf("NO\n");
                return;
            }
            a.erase(a.find(x));
            a.insert(x/2);
        }
        else{
            b.erase(b.find(*a.rbegin()));
            a.erase(a.find(*a.rbegin()));
        }
    }
    printf("YES\n");
}
int main(){
    int t=1;
    scanf("%d",&t);
    //printf("\"");
    while(t--){
        // cerr<<t<<endl;
        solve();
     //   cerr<<t<<endl;
    }
    
   // cerr<<cnt<<endl;
}
/*
*/