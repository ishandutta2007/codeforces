#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <math.h>
#include <cassert>
#include <map>
#include <string>
#include <set>
#include <cstring>

using namespace std;

long long sumNumber[50000];
char input[4005];
int a;

int main()
{
    scanf("%d%s", &a, input);
    long long len=strlen(input);
    for(int i=0; input[i]; ++i){
        int sum=0;
        for(int j=i; input[j]; ++j){
            sum += input[j]-'0';
            ++sumNumber[sum];
        }
    }
    /*if(!a){
        printf("%I64d\n", 2*len*sumNumber[0]-sumNumber[0]*sumNumber[0]);

    }else{*/
        long long ans=0;
        for(int i=0; i < 50000; ++i){
            if((!i && !a) || (i && a%i == 0)){
                if(i && a/i < 50000)ans += sumNumber[i]*sumNumber[a/i];
                else if(!i) ans += sumNumber[i]*(len*(len+1))/2;
            }
        }
        /*if(!a)
            ans += sumNumber[0]*sumNumber[0];*/
        printf("%I64d\n", ans);
    //}
    return 0;
}