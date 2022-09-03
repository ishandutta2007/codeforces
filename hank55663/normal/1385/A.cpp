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
        int x,y,z;
        scanf("%d %d %d",&x,&y,&z);
        if(x==y){
            if(z>x)printf("NO\n");
            else{
                printf("YES\n%d %d %d\n",x,z,z);
            }
        }
        else if(y==z){
            if(x>z)printf("NO\n");
            else{
                printf("YES\n%d %d %d\n",x,x,z);
            }
        }
        else if(x==z){
            if(y>z)printf("NO\n");
            else{
                printf("YES\n%d %d %d\n",y,y,x);
            }
        }
        else{
            printf("NO\n");
        }
    }
}