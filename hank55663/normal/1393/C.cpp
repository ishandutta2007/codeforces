#include<bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define pll pair<LL,LL>
#define pii pair<int,int>
#define y second
#define x first
#define LL long long 
using namespace std;
void solve(){
    int n;
    scanf("%d",&n);
    int cnt[100005];
    fill(cnt,cnt+n+1,0);
    int a[100005];
    for(int i = 0 ; i < n ; i++){
        
        scanf("%d",&a[i]);
        cnt[a[i]]++;
    }
    int Max=n,Min=0;
    while(Max>Min+1){
        int mid=(Max+Min)/2;
        int Maxm=n/(mid+1);
        int more=n%(mid+1);
        for(int i = 1;i<=n;i++){
            if(cnt[i]>Maxm+1)more=-1;
            else if(cnt[i]==Maxm+1)more--;
        }
        //printf("%d %d %d %d %d\n",Max,Min,mid,more,Maxm);
        if(more>=0)Min=mid;
        else Max=mid;
    }
    printf("%d\n",Min);
}
int main(){
    int t=1;
    scanf("%d",&t);
    while(t--){
        solve();
    }
}
/*
100
5
5 4
4 2
4 2 3
5 4 2 3 1
*/