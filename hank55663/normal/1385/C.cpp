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
        scanf("%d",&n); 
        int a[200005];
        for(int i = 0;i<n;i++)scanf("%d",&a[i]);
        int go=0;
        int vis=0;
        for(int i = n-2;i>=0;i--){
            if(!go){
                if(a[i]<a[i+1])go=1;
            }
            else{
                if(a[i]>a[i+1]){
                    vis=1;
                    printf("%d\n",i+1);
                    break;
                }
            }
        }
        if(!vis)printf("0\n");
    
    }
}