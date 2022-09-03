#include<bits/stdc++.h>
using namespace std;
#include <bits/extc++.h>
using namespace __gnu_pbds;
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int a,b,n;
        scanf("%d %d %d",&a,&b,&n);
        if(n%3==0)printf("%d\n",a);
        else if(n%3==1)printf("%d\n",b);
        else printf("%d\n",a^b);
    }
}