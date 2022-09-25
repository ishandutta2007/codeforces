#include <cstdio>
using namespace std;
int n;
int arr[100005];
int main(){
    scanf("%d",&n);
    int k=1;
    long long iter;
    for (int x=2;x<=n;x++){
        if (arr[x]==0){
            arr[x]=k;
            iter=((long long)x)*x;
            while (iter<=n){
                arr[iter]=k;
                iter+=x;
            }
            k++;
        }
    }
    for (int x=2;x<=n;x++) printf("%d ",arr[x]);
}