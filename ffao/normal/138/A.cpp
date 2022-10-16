#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <list>
#include <string>
#include <iostream>

using namespace std;

#define AABB 0
#define ABBA 1
#define ABAB 2

string quatrain[4];

int main() {
    int N, K;
    scanf("%d %d", &N, &K);
    getchar();
    
    int scheme = -1;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < 4; j++) {
            getline(cin, quatrain[j]);
        }
        
        for (int j = 0; j < 4; j++) {
            int vowel = 0;
            int k = quatrain[j].size();
            while (vowel != K && k > 0) {
                k--;
                if (quatrain[j][k] == 'a' || quatrain[j][k] == 'i' ||quatrain[j][k] == 'u'|| quatrain[j][k] == 'o'|| quatrain[j][k] == 'e') {
                    vowel++;
                }
            }  
            
            if (vowel != K) {
                printf("NO\n");
                return 0;
            }
            
            quatrain[j] = quatrain[j].substr(k);
        }
        
        bool fm = quatrain[0] == quatrain[1];
        bool mm = quatrain[1] == quatrain[2];
        bool em = quatrain[2] == quatrain[3];
        bool om = quatrain[0] == quatrain[3];
        bool am = quatrain[0] == quatrain[2];
        bool am2 = quatrain[1] == quatrain[3];
        
        if (fm && mm && em) continue;
        else if (fm && em) {
            if (scheme != AABB && scheme != -1) { printf("NO\n"); return 0; }
            scheme = AABB;
        }
        else if (mm && om) {
            if (scheme != ABBA && scheme != -1) { printf("NO\n"); return 0; }
            scheme = ABBA;
        }
        else if (am && am2) {
            if (scheme != ABAB && scheme != -1) { printf("NO\n"); return 0; }
            scheme = ABAB;
        }
        else { printf("NO\n"); return 0; }
    }
    
    if (scheme == -1) printf("aaaa\n");
    else if (scheme == ABAB) printf("abab\n");
    else if (scheme == AABB) printf("aabb\n");
    else if (scheme == ABBA) printf("abba\n");
}