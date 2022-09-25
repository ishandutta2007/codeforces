#include <cstdio>
using namespace std;
int n;
int k;
int main(){
    scanf("%d",&n);
    getchar();
    for (int x=0;x<n;x++){
        if (getchar()=='(') k++;
        else k--;
        if (k<-1){
            printf("No");
            return 0;
        }
    }
    if (k==0) printf("Yes");
    else printf("No");
}