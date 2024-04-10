#include <vector> 
#include <list> 
#include <map> 
#include <set> 
#include <queue>
#include <stack> 
#include <bitset> 
#include <algorithm> 
#include <numeric> 
#include <utility> 
#include <sstream> 
#include <iostream> 
#include <iomanip> 
#include <cstdio> 
#include <cmath> 
#include <cstdlib> 
#include <ctime> 
#include <cstring> 

using namespace std;

typedef long long ll; 
typedef pair<int, int> pii;

#define REP(i,n) for((i)=0;(i)<(int)(n);(i)++)

int n;

struct kk {
    pii k;
    int id;
};

vector<kk> q[1000][1000];

bool upsort(const kk& a, const kk& b) {
    return a.k.second < b.k.second;
}
bool downsort(const kk& a, const kk& b) {
    return a.k.second > b.k.second;
}
bool rightsort(const kk& a, const kk& b) {
    return a.k.first < b.k.first;
}
bool leftsort(const kk& a, const kk& b) {
    return a.k.first > b.k.first;
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        kk k;
        scanf("%d %d", &k.k.first, &k.k.second); k.id = i; 
        q[min(999, k.k.first/1000)][min(999, k.k.second/1000)].push_back(k);
    }

    for (int i = 0; i < 500; i++) {
        for (int j = 0; i+j <= 999-i; j++) {
            vector<kk>& qq = q[i][i+j];
            sort(qq.begin(), qq.end(), upsort);
            for (kk k : qq) printf("%d ", k.id+1);
        }
        for (int j = 1; i+j <= 999-i; j++) {
            vector<kk>& qq = q[i+j][999-i];
            sort(qq.begin(), qq.end(), rightsort);
            for (kk k : qq) printf("%d ", k.id+1);
        }
        for (int j = 1; 999-i-j >= i; j++) {
            vector<kk>& qq = q[999-i][999-i-j];
            sort(qq.begin(), qq.end(), downsort);
            for (kk k : qq) printf("%d ", k.id+1);
        }
        for (int j = 1; 999-i-j > i; j++) {
            vector<kk>& qq = q[999-i-j][i];
            sort(qq.begin(), qq.end(), leftsort);
            for (kk k : qq) printf("%d ", k.id+1);
        }
    }
}