#include<bits/stdc++.h>
#define pb push_back
#define F first
#define S second
using namespace std;
typedef pair<int,int>pi;
typedef long long ll;
const int M=1000000007;
const int maxn=1000006;
int n,a[maxn],l[maxn],r[maxn];
vector<pi> b;
int main(){
    scanf("%d",&n);
    for (int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        if (!l[a[i]]) l[a[i]]=i;
        r[a[i]]=i;
    }
    for (int i=1;i<=n;i++) if (l[i]) b.pb((pi){l[i],r[i]});
    sort(b.begin(),b.end());
    int res=0;
    pi cur=(pi){-1,-1},last=(pi){-1,-1};
    for (auto x:b){
        if (x.S<cur.S) continue;
        if (x.F>cur.S) {
            last=x; cur=x;
            if (x.F<x.S) res+=2; else res++;
        } else {
            if (cur==last){
                cur=x; res++;
            } else if (x.F<last.S){
                cur=x;
            } else {
                last=cur; cur=x;
                res++;
            }
        }
    }
    cout << n-res << endl;
}