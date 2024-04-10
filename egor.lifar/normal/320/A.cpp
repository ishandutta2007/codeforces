#include <vector>
#include <algorithm>
#include <iostream>
#include <string>
#include <string.h> 
#include <cstdio>


using namespace std;


int main()
{   string s;
    cin >> s;
    int n = s.size();
    for(int i =0; i<n; i++){
        if(s[i] != '1' && s[i]!='4'){
            printf("NO");
            return 0;
        }
        if(i + 2 < n){
            if(s[i] == '4' && s[i+1] == '4' && s[i+2] == '4'){
                printf("NO");
                return 0;
            }
        }
    } 
    if(s[0] == '4'){
        printf("NO");
        return 0;
    }
    printf("YES");


    return 0;
}