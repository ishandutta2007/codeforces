#include <cstdio>
#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;
int main(){
    int TC;
    scanf("%d",&TC);
    while (TC--){
        int a,b;
        cin>>a>>b;
        
        a=abs(a-b);
        
        int temp;
        for (int x=0;;x++){
            temp=x*(x+1)/2;
            
            if ((temp&1)==(a&1) && temp>=a){
                printf("%d\n",x);
                break;
            }
        }
    }
}