    #include <string.h>
    #include <stdio.h>
    #include <algorithm>
    #include <set>

    using namespace std;

    char inp[100010];

    int c0 = 0, c1 = 0, ci = 0;

    int main() {
        gets(inp);
       
        int len = strlen(inp);
       
        for (int i = 0; i < len; i++) {
            if (inp[i] == '1') c1++;
            else if (inp[i] == '0') c0++;
            else if (inp[i] == '?') ci++;
        }
       
       
        if (c0+ci > c1) printf("00\n");
       
        if ( ci>=abs(c0-c1) || ci == c1-c0-1 ) {
             if (inp[len-1] == '1') printf("01\n");
             else if (inp[len-1] == '0') printf("10\n");
             else {
                if (c0 >= c1 && ((ci == c0-c1) || (ci == c0+1-c1)) ) printf("01\n");
                else if (c1 > c0 && ((ci == c1-c0) || (ci == c1-c0-1)) ) printf("10\n");
                else printf("01\n10\n");  
             }
        }
        if (c1+ci > c0+1) printf("11\n");
    }