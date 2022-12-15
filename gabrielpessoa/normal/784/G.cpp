#include <bits/stdc++.h>
using namespace std;

char s[50];
int ptr = 0;

int getNext() {
    int i = 0;
    while(s[ptr] >= '0' && s[ptr] <= '9') {
        i = i * 10 + s[ptr++] - '0';
    }
    return i;
}

int tenpow(int n) {
    int r = 1;
    while(n-- > 0) {
        r *= 10;
    }
    return r;
}

int digits(int n) {
    int r = 0;
    while(n >= 10) {
        n /= 10;
        r++;
    }
    return r;
}

int main() {
    scanf("%s", s);
    int n = getNext();
    while(s[ptr] != '\0') {
        if(s[ptr++] == '+') {
            n += getNext();
        } else {
            n -= getNext();
        }
    }
    for(int i = digits(n); i >= 0; i--) {
        int k = (n / tenpow(i)) % 10;
        for(int j = 0; j < k; j++) {
            printf("+");
        }
        printf("++++++++++++++++++++++++++++++++++++++++++++++++.>");
    }
    return 0;
}