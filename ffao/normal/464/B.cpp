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

#define INF 1000000000
#define pb push_back 
#define itr iterator 
#define sz size() 
#define mp make_pair

struct point {
    long long x, y, z;

    bool operator== (point ot) {
        return x == ot.x && y == ot.y && z == ot.z;
    }
};

point inp[10];
point all[10];
long long dist[10];

long long norm(const point& a, const point& b) {
    long long dx = a.x-b.x;
    long long dy = a.y-b.y;
    long long dz = a.z-b.z;
    return dx*dx+dy*dy+dz*dz;
}

bool is_cube() {
    for (int i = 0; i < 8; i++) {
        for (int j = i+1; j < 8; j++) {
            if (all[i] == all[j]) return false;
        }
    }

    /*printf("testing...\n");
    for (int i = 0; i < 8; i++) {
        cout << all[i].x << " " << all[i].y << " " << all[i].z << endl;
    }*/

    point center;
    center.x = 0; center.y = 0; center.z = 0;

    for (int i = 0; i < 8; i++) {
        center.x += all[i].x; center.y += all[i].y; center.z += all[i].z;
    }
    center.x /= 8; center.y /= 8; center.z /= 8;
    //printf("cent %lld %lld %lld\n", center.x, center.y, center.z);
    long long t = norm(center, all[0]);

    for (int i = 0; i < 8; i++) {
        //printf("centno %lld\n", norm(center, all[i]));
        if (norm(center, all[i]) != t) return false;

        for (int j = 0; j < 8; j++) if (j != i) {
            dist[j > i ? j-1 : j] = norm(all[i], all[j]);
        }

        sort(dist, dist+7);

        /*for (int i = 0; i < 7; i++) {
            printf("dist[%d] = %lld\n", i, dist[i]);
        }*/

        if (dist[0] == dist[1] && dist[1] == dist[2]) {
            if (dist[3] == dist[4] && dist[4] == dist[5] && dist[3] == 2*dist[0]) {
                if (dist[0]*3 == dist[6]) {
                    continue;
                }
            }
        }

        return false;
    }

    return true;
}

bool rec(int i) {
    if (i == 8) {
        return is_cube();
    }

    for (int p = 0; p < 6; p++) {
        all[i].x = inp[i].x;
        all[i].y = inp[i].y;
        all[i].z = inp[i].z;

        if (p == 1) swap(all[i].y, all[i].z);
        if (p == 2) {
            swap(all[i].x, all[i].y);
        }
        if (p == 3) {
            swap(all[i].x, all[i].y);
            swap(all[i].y, all[i].z);
        }
        if (p == 4) {
            swap(all[i].x, all[i].z);
        }
        if (p == 5) {
            swap(all[i].x, all[i].z);
            swap(all[i].y, all[i].z);
        }

        if (rec(i+1)) return true;
    }

    return false;
}

int main() {
    for (int i = 0; i < 8; i++) {
        cin >> inp[i].x >> inp[i].y >> inp[i].z;
        inp[i].x *= 8; inp[i].y *= 8; inp[i].z *= 8;
    }

    if (rec(0)) {
        cout << "YES" << '\n';
        for (int i = 0; i < 8; i++) {
            cout << all[i].x/8 << " " << all[i].y/8 << " " << all[i].z/8 << endl;
        }
    }
    else cout << "NO";
}