#include <vector>
#include <algorithm>
#include <iostream>
#include <string>
#include <string.h> 
#include <cstdio>


using namespace std;


int main()
{   
    string s, s2, s3, s4;
    cin >>s >> s2 >> s4;
    s3 = s + s2;
    sort(s4.begin(), s4.end());
    sort(s3.begin(), s3.end());
    if(s3 == s4){
        printf("YES\n");
    } else {
        printf("NO\n");
    }
    return 0;
}