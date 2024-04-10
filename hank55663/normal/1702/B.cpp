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
    char c[200005];
    scanf("%s",c);
    int now=0;
    for(int i = 1;;i++){
        set<char> s;
        while(c[now]!=0&&(s.size()<=2||s.find(c[now])!=s.end())){
            
            s.insert(c[now]);
            now++;
        }
        if(c[now]==0){
            printf("%d\n",i);
            return;
        }
    }
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