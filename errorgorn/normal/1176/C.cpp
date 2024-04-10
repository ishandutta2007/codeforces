#include <cstdio>
using namespace std;
int n;
int arr[6]; ///4,8,15,16,23,42
int t;
int main(){
    scanf("%d",&n);
    for (int x=0;x<n;x++){
        scanf("%d",&t);
        if (t==4){
            arr[0]++;
        }
        else if (t==8){
            if (arr[0]){
                arr[0]--;
                arr[1]++;
            }
        }
        else if (t==15){
            if (arr[1]){
                arr[1]--;
                arr[2]++;
            }
        }
        else if (t==16){
            if (arr[2]){
                arr[2]--;
                arr[3]++;
            }
        }
        else if (t==23){
            if (arr[3]){
                arr[3]--;
                arr[4]++;
            }
        }
        else{
            if (arr[4]){
                arr[4]--;
                arr[5]++;
            }
        }
    }
    printf("%d\n",n-arr[5]*6);
}