#include <vector>
#include <algorithm>
#include <iostream>
#include <string>
#include <string.h> 
#include <cstdio>


using namespace std;


int main()
{   
    int n, a[100];
    string s;
    scanf("%d", &n);
    cin >> s;
    for(int i =0; i<n; i++){
        if(s[i] != '4' && s[i] != '7'){
            printf("NO");
            return 0;
        }
        a[i] = s[i] - '0';
    }
    int k = 0, k2 = 0;
    for(int i =0; i < n / 2; i++){
        k += a[i];
    }
    for(int i = n / 2; i < n; i++){
        k2 += a[i];
    }
    if(k == k2){
        printf("YES\n");
    } else {
        printf("NO\n");
    }
    return 0;
}