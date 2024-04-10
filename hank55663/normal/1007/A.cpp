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
#define EPS 1e-4
#define arg ARG
#define cpdd const pdd
#define ld long double
int main(){
    int n;
    scanf("%d",&n);
    int a[100005];
    multiset<int> s;
    for(int i =0;i<n;i++){
        scanf("%d",&a[i]);
        s.insert(a[i]);
    }
    sort(a,a+n);
    int res=0;
    for(int i =0;i<n;i++){
        if(s.lower_bound(a[i])!=s.begin()){
            s.erase(prev(s.lower_bound(a[i])));
            res++;
        }
    }
    printf("%d\n",res);
}