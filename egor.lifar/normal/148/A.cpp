#include <vector>
#include <algorithm>
#include <iostream>
#include <string>
#include <string.h> 
#include <cstdio>


using namespace std;


int main()
{   
    int k, l, m, n, d, a[100000];
    scanf("%d %d %d %d %d", &k, &l, &m, &n, &d);
    for(int i =1; i<=d; i++){
        a[i] = 0;
    }
    for(int i =1; i<=d; i++){
        if(i % k ==  0 || i % l == 0 || i % m == 0 || i % n == 0){
            a[i] = 1;
        }
    }
    int s = 0;
    for(int i =1; i<=d; i++){
        if(a[i] == 1){
            s++;
        }
    }
    printf("%d\n", s);


    return 0;
}