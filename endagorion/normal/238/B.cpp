#include <iostream>
#include <vector>
#include <cmath>
#include <cstdio>
#include <set>
#include <map>
#include <fstream>
#include <cstdlib>
#include <string>
#include <cstring>
#include <algorithm>

using namespace std;

#ifdef ONLINE_JUDGE

#define fin cin
#define fout cout

#else

fstream fin("input.txt", fstream::in);
fstream fout("output.txt", fstream::out);

#endif

struct TNum {
    int x;
    int i;

    TNum(int _x = 0, int _i = 0)
        : x(_x)
        , i(_i)
    {
    }

    bool operator<(const TNum &a) const {
        return x > a.x;
    }
};

int main() {
	fout.precision(10);
	fout << fixed;

    int N, H;
    fin >> N >> H;
    vector<TNum> nums(N);
    for (int i = 0; i < N; ++i) {
        fin >> nums[i].x;
        nums[i].i = i;
    }
    sort(nums.begin(), nums.end());
    vector<int> maxD(N), minD(N);
    if (N == 2) {
        fout << 0 << '\n';
        fout << "1 1\n";
        return 0;
    }
    int ans = 1e9;
    int mi = -1;
    int tail = nums[N - 1].x + min(nums[N - 2].x + H, nums[N - 3].x);
    for (int i = 1; i < N; ++i) {
        int res;
        if (i > 1) {
            res = nums[0].x + nums[1].x;
        } else {
            res = 0;
        }
        res = max(res, nums[0].x + nums[i].x + H);
        if (i < N - 1) {
            res -= tail;
        } else {
            res -= min(nums[N - 1].x + nums[N - 2].x + H, nums[N - 2].x + nums[N - 3].x);
        }
        if (res < ans) {
            ans = res;
            mi = i;
        }
    }
    if (nums[0].x + nums[1].x - nums[N - 2].x - nums[N - 1].x < ans) {
        ans = nums[0].x + nums[1].x - nums[N - 2].x - nums[N - 1].x;
        mi = N;
    }

    vector<int> anss(N);
    for (int i = 0; i < mi; ++i) {
        anss[nums[i].i] = 1;
    }
    if (mi < N) {
        anss[nums[mi].i] = 2;
    }
    for (int i = mi + 1; i < N - 2; ++i) {
        anss[nums[i].i] = 1;
    }
    if (anss[nums[N - 2].i] == 0) {
        anss[nums[N - 2].i] = 3 - anss[nums[N - 3].i];
    }
    if (anss[nums[N - 1].i] == 0) {
        anss[nums[N - 1].i] = 3 - anss[nums[N - 2].i];
    }
    fout << ans << '\n';
    for (int i = 0; i < N; ++i) {
        fout << anss[i] << ' ';
    }
    fout << '\n';

	return 0;
}