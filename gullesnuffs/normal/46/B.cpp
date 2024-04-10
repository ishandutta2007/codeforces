#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <map>

using namespace std;

string name[5]={"S", "M", "L", "XL", "XXL"};

int main(){
    int N[5];
    int K;
    for(int i=0; i < 5; ++i)
        scanf("%d", N+i);
    scanf("%d", &K);
    for(int i=0; i < K; ++i){
        string s;
        cin >> s;
        int j;
        for(j=0; s != name[j]; ++j);
        int best=-1000;
        for(int k=0; k < 5; ++k){
            if(!N[k])
                continue;
            if(abs(k-j) <= abs(best-j))
                best=k;
        }
        cout << name[best] << "\n";
        --N[best];
    }
    return 0;
}