#include <cstdlib>
#include <cctype>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <fstream>
#include <numeric>
#include <iomanip>
#include <bitset>
#include <list>
#include <stdexcept>
#include <functional>
#include <utility>
#include <ctime>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MAX(a,b) ((a) > (b) ? (a) : (b))
#define MIN(a,b) ((a) < (b) ? (a) : (b))
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e17;
const int N = 1e4;
map<int, string> m;
int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    m[0] = "zero";
    m[1] = "one";
    m[2] = "two";
    m[3] = "three";
    m[4] = "four";
    m[5] = "five";
    m[6] = "six";
    m[7] = "seven";
    m[8] = "eight";
    m[9] = "nine";
    m[10] = "ten";
    m[11] = "eleven";
    m[12] = "twelve";
    m[13] = "thirteen";
    m[14] = "fourteen";
    m[15] = "fifteen";
    m[16] = "sixteen";
    m[17] = "seventeen";
    m[18] = "eighteen";
    m[19] = "nineteen";
    m[20] = "twenty";
    m[21] = "twenty-one";
    m[22] = "twenty-two";
    m[23] = "twenty-three";
    m[24] = "twenty-four";
    m[25] = "twenty-five";
    m[26] = "twenty-six";
    m[27] = "twenty-seven";
    m[28] = "twenty-eight";
    m[29] = "twenty-nine";
    m[30] = "thirty";
    m[31] = "thirty-one";
    m[32] = "thirty-two";
    m[33] = "thirty-three";
    m[34] = "thirty-four";
    m[35] = "thirty-five";
    m[36] = "thirty-six";
    m[37] = "thirty-seven";
    m[38] = "thirty-eight";
    m[39] = "thirty-nine";
    m[40] = "forty";
    m[41] = "forty-one";
    m[42] = "forty-two";
    m[43] = "forty-three";
    m[44] = "forty-four";
    m[45] = "forty-five";
    m[46] = "forty-six";
    m[47] = "forty-seven";
    m[48] = "forty-eight";
    m[49] = "forty-nine";
    m[50] = "fifty";
    m[51] = "fifty-one";
    m[52] = "fifty-two";
    m[53] = "fifty-three";
    m[54] = "fifty-four";
    m[55] = "fifty-five";
    m[56] = "fifty-six";
    m[57] = "fifty-seven";
    m[58] = "fifty-eight";
    m[59] = "fifty-nine";
    m[60] = "sixty";
    m[61] = "sixty-one";
    m[62] = "sixty-two";
    m[63] = "sixty-three";
    m[64] = "sixty-four";
    m[65] = "sixty-five";
    m[66] = "sixty-six";
    m[67] = "sixty-seven";
    m[68] = "sixty-eight";
    m[69] = "sixty-nine";
    m[70] = "seventy";
    m[71] = "seventy-one";
    m[72] = "seventy-two";
    m[73] = "seventy-three";
    m[74] = "seventy-four";
    m[75] = "seventy-five";
    m[76] = "seventy-six";
    m[77] = "seventy-seven";
    m[78] = "seventy-eight";
    m[79] = "seventy-nine";
    m[80] = "eighty";
    m[81] = "eighty-one";
    m[82] = "eighty-two";
    m[83] = "eighty-three";
    m[84] = "eighty-four";
    m[85] = "eighty-five";
    m[86] = "eighty-six";
    m[87] = "eighty-seven";
    m[88] = "eighty-eight";
    m[89] = "eighty-nine";
    m[90] = "ninety";
    m[91] = "ninety-one";
    m[92] = "ninety-two";
    m[93] = "ninety-three";
    m[94] = "ninety-four";
    m[95] = "ninety-five";
    m[96] = "ninety-six";
    m[97] = "ninety-seven";
    m[98] = "ninety-eight";
    m[99] = "ninety-nine";
    int n;
    cin >> n;
    cout << m[n] << endl;
    return 0;
}