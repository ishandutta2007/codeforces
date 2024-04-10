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
    int n;
    scanf("%d",&n);
    int a[200005];
    for(int i = 0;i<n;i++){
        scanf("%d",&a[i]);
    }
    sort(a,a+n);
    if(a[2]<0){
        printf("NO\n");
        return ;
    }
    reverse(a,a+n);
    if(a[2]>0){
        printf("NO\n");
        return;
    }
    vector<int> v;
    set<int> s;
    for(int i = 0;i<n;i++){
        if(a[i]==0&&v.size()&&v.back()==0);
        else
        v.pb(a[i]);
        s.insert(a[i]);
    }
    for(int i = 0;i<v.size();i++){
        for(int j = i+1;j<v.size();j++){
            for(int k = j+1;k<v.size();k++){
                if(s.find(v[i]+v[j]+v[k])==s.end()){
                    printf("No\n");
                    return;
                }
            }
        }
    }
    printf("Yes\n");
}
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        solve();
    }
}
/*
p*t = a^2+b^2
q*t = ab
(p+2*q)*t=(a+b)^2
*/