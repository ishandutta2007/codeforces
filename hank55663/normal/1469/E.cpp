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
set<int> s;
bool solve(){
    int n,k;
    scanf("%d %d",&n,&k);
    char c[1000005];
    scanf("%s",c);
    vector<int> v;
    if(k<=21){
        for(int i = 0;c[i+k-1]!=0;i++){
            int val=0;
            for(int j = 0;j<k;j++){
                if(c[i+j]=='0')val+=(1<<(k-j-1));
            }
            if(s.find(val)!=s.end()){
                s.erase(val);
                v.pb(val);
            }
        }
        if(*s.begin()<(1<<k)){
            int x=*s.begin();
            printf("YES\n");
            for(int i=k-1;i>=0;i--){
                if(x&(1<<i))printf("1");
                else printf("0");
            }
            printf("\n");
        }
        else{
            printf("NO\n");
        }
    }
    else{
       // vector<int> v;
        int pool[1000005];
        int *pre = pool+1;
        MEM(pool);
        for(int i = 0;c[i]!=0;i++){
            pre[i]=pre[i-1];
            if(c[i]=='0')pre[i]++;
        }
        for(int i = 0;c[i+k-1]!=0;i++){
            int val=0;
            for(int j=k-20;j<k;j++){
                if(c[i+j]=='0')val+=(1<<(k-j-1));
            }
             if(pre[i+k-21]-pre[i-1]==0)
            if(s.find(val)!=s.end()){
                s.erase(val);
                v.pb(val);
            }
        }
        printf("YES\n");
        for(int i = 0;i<k-20;i++)printf("0");
        int res=*s.begin();
        for(int i = k-1;i>=k-20;i--){
            if(res&(1<<(i-(k-20))))printf("1");
            else printf("0");
        }
        printf("\n");
    }
    for(auto it:v)s.insert(it);
    return true;
}
int main(){
    int t=1;00000;//0000;//00000;//000000;//000000;
    scanf("%d",&t);
    for(int i = 0;i<(1<<21);i++)s.insert(i);
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