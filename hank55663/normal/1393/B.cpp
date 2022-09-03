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
   // int a[100005];
    int cnt[100005];
    fill(cnt,cnt+100005,0);
    int two=0,four=0;
    for(int i = 1;i<=n;i++){
        int x;
        scanf("%d",&x);
        cnt[x]++;
        if(cnt[x]%2==0)two++;
        if(cnt[x]%4==0)four++;
    }
    int q;
    scanf("%d",&q);
    while(q--){
        char c;
        int x;
        scanf(" %c %d",&c,&x);
        if(c=='+'){
            cnt[x]++;
            if(cnt[x]%2==0)two++;
            if(cnt[x]%4==0)four++;
        }
        else{
             if(cnt[x]%2==0)two--;
            if(cnt[x]%4==0)four--;
            cnt[x]--;
        }
        //printf("%d %d\n",two,four);
        if(four&&two-2>=2){
            printf("YES\n");
        }
        else{
            printf("NO\n");
        }
    }
    //printf("%d\n",n/2+1);
}
int main(){
    int t=1;
    //scanf("%d",&t);
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