#include <bits/stdc++.h>

using namespace std;

int b2, b3, b4, a23, a24, a34, i23, e4, l3, i4, i24, i34;
string s1, s2, s3, s4;

void cant() {
    puts("-1");
    exit(0);
}

int main() {
    scanf("%d %d %d %d %d %d", &b2, &b3, &b4, &a23, &a24, &a34);

    s1.resize(400000, 'a'); s2.resize(400000, 'a');
    s3.resize(400000, 'a'); s4.resize(400000, 'a');

    for(int i = 0; i < b2; i++) s2[i] = 'b';

    if((b2 + b3 - a23) % 2 != 0) cant();
    i23 = (b2 + b3 - a23) / 2;
    if(i23 < 0 || i23 > b2 || i23 > b3) cant();

    for(int i = b2 - i23, j = 0; j < b3; j++, i++) s3[i] = 'b', l3 = i;

    int q2 = b2 + b4 - a24;
    int q3 = b3 + b4 - a34;
    if(q2 < 0 || q3 < 0 || q2 % 2 || q3 % 2) cant();
    q2 /= 2; q3 /= 2;

    i4 = min({q2, q3, i23, b4});

    i24 = q2 - i4;
    if(i24 > b2 - i23) cant();
    i34 = q3 - i4;
    if(i34 > b3 - i23) cant();
    if(i4 + i24 + i34 > b4) cant();

    int reduce = min({i4, b2 - i23 - i24, b3 - i23 - i34, b4 - i4 - i24 - i34});
    i4 -= reduce;
    i24 += reduce;
    i34 += reduce;

    for(int i = 0; i < i24; i++) s4[i] = 'b';
    for(int i = b2 - i23, j = 0; j < i4; i++, j++) s4[i] = 'b';
    for(int i = l3, j = 0; j < i34; i--, j++) s4[i] = 'b';
    for(int i = l3 + 1, j = 0; j < b4 - i24 - i4 - i34; j++, i++) s4[i] = 'b';


    while(s2.back() == 'a' && s3.back() == 'a' && s4.back() == 'a') {
        s1.pop_back();
        s2.pop_back();
        s3.pop_back();
        s4.pop_back();
    }
    printf("%d\n%s\n%s\n%s\n%s\n", s1.size(), s1.c_str(), s2.c_str(), s3.c_str(), s4.c_str());
    return 0;
}