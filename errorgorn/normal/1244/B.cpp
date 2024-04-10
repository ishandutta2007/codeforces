#include <cstdio>
#include <algorithm>
using namespace std;
int main(){
    int TC;
    scanf("%d",&TC);
    int n;
    int mini,maxi;
    int best;
    while (TC--){
        scanf("%d",&n);
        getchar();
        mini=1000000;
        maxi=-1;
        best=0;
        for (int x=0;x<n;x++){
            if (getchar()=='1'){
                mini=min(mini,x);
                maxi=max(maxi,x);
            }
        }
        if (maxi==-1){
            best=n;
        }
        else if (mini==maxi){
            best=max((maxi+1)*2,(n-mini)*2);
        }
        else{
            best=max((maxi-mini+1)*2+max(mini,n-maxi-1),max((maxi+1)*2,(n-mini)*2));

        }
        printf("%d\n",best);
    }
}