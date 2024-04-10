#include<bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define pii pair<int,int>
#define y second
#define x first
#define LL long long 
using namespace std;
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int n;
        int a[55];
        scanf("%d",&n);
        for(int i =0;i<n;i++){
            scanf("%d",&a[i]);
        }
        sort(a,a+n);
        int ok=1;
        for(int i = 0;i<n-1;i++){
            if(a[i+1]-a[i]>1)ok=0;
        }
        if(ok)printf("YES\n");
        else printf("NO\n");
    }
}