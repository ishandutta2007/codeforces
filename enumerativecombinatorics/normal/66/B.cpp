#include<stdio.h>
#include<algorithm>
using namespace std;
int t[1000];
int main(){
    int a;
    scanf("%d",&a);
    for(int i=0;i<a;i++)scanf("%d",t+i);
    int ret=0;
    for(int i=0;i<a;i++){
        int L=t[i];
        int val=1;
        for(int j=i-1;j>=0;j--){
            if(t[j]<=L){
                L=t[j];
                val++;
            }
            else break;
        }
        int R=t[i];
        for(int j=i+1;j<a;j++){
            if(t[j]<=R){
                R=t[j];
                val++;
            }
            else break;
        }
        ret=max(ret,val);
    }
    printf("%d\n",ret);
}