#include <bits/stdc++.h>

using namespace std;

string str;
int z[1000100], sz, match1[1000100], match2[1000100], max1=-1,max2=-1;

void z_f() {
    int L=0, R=0;
    for(int i=1; i < sz; i++) {
        if(i > R) {
            L = R = i;
            while(R < sz && str[R] == str[R-L]) R++;
            z[i] = R - L;
            R--;
        }
        else {
            int k = i - L;
            if(z[k] < R - i + 1) z[i] = z[k];
            else {
                L = i;
                while(R < sz && str[R] == str[R-L]) R++;
                z[i] = R - L;
                R--;
            }
        }
    }
}

int main() {
    char s[1000100];
    scanf("%s",s);
    str = s;

    sz = str.size();
    z_f();

    for(int i=0;i<sz;i++) {
        if(i + z[i] < sz) {
            max1 = max(max1, z[i]);
            match1[z[i]]++;
        }
        if(i + z[i] == sz) {
            max2 = max(max2, z[i]);
            match2[z[i]]++;
        }
    }

    for(int i=sz;i>0;i--) {
        if((match1[i] && match2[i])
           || (match2[i] && (max2 > i || max1 >= i))) {
            for(int j=0;j<i;j++) printf("%c",str[j]);
            printf("\n");
            return 0;
        }
    }

    printf("Just a legend\n");
    return 0;
}

// aczzzazzzzzac
// 0000010000012
// 9000010000020