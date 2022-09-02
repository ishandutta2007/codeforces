#include<cstdio>
#include<algorithm>
#include <iostream>
using namespace std;
int num1[105],num2[105],n,i,c1=0,c2=0,c=0,j;
int main(){
    scanf("%d",&n);
    for(i=0;i<n;i++){
        int a,b;
        scanf("%d %d",&a,&b);
        c+=a;
        if(a==1){num1[c1]=b; c1++;}
        else{num2[c2]=b; c2++;}
    }
    sort(num1,num1+c1);
    sort(num2,num2+c2);
    int ret=20000000;
    for(int i=0;i<=c1;i++){
        int we=0;
        for(int k=0;k<i;k++){
            we+=num1[k];
        }
        int d=c-i;
        for(int j=0;j<=c2;j++){
            if(d>=we){
                ret=min(ret,d);
                we+=num2[j];
                d-=2;
            }
        }
    }
    cout << ret << endl;
}