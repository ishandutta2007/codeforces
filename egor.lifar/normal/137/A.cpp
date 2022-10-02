#include <vector>
#include <algorithm>
#include <iostream>
#include <string>
#include <string.h> 
#include <cstdio>


using namespace std;


int main()
{   
    string s;
    cin >> s;
    int n = s.size();
    int k = 0;
    int b = 0;
    for(int i = 0; i<n; i++){
        if(i != 0 && s[i] == s[i-1] || i == 0){
            b++;
        }else{
            k += b / 5;
            if(b % 5 != 0){
                k++;
            } 
            b = 1;
        }
    }
    k += b / 5;
    if(b % 5 != 0){
       k++;
    }
    printf("%d\n", k);
    return 0;
}