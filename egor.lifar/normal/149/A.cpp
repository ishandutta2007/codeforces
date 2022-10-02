#include <vector>
#include <algorithm>
#include <iostream>
#include <string>
#include <string.h> 
#include <cstdio>


using namespace std;


int main()
{   

    int k, a[12];
    scanf("%d", &k);
    for(int i =0; i<12; i++){
        scanf("%d", &a[i]);
    }
    sort(a, a + 12);
    int m = 0;
    int n = 0;
    int i =11;
    while(m < k && i+1>=0){
        m+=a[i];
        i--;
        n++;
    }
    if(i < -1){
        printf("-1\n");
    } else {
        printf("%d\n", n);
    }
    return 0;
}