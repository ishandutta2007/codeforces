#include <iostream>
#include <string>
#include <sstream>

using namespace std;

bool isNumber(char x) {
    return x >= '0' && x <= '9';
}

string toSecond(string S) {
    int row = 1;
    int count = 26;
    int i;

    for (i = 1; !isNumber(S[i]); ++i) {
        row += count;
        count *= 26;
    }

    count /= 26;

    for (i = 0; !isNumber(S[i]); ++i) {
        row += 1u * (S[i] - 'A') * count;
        count /= 26;
    }

    stringstream answer;
    answer << "R" << S.substr(i) << "C" << row;
    return answer.str();
}

string toFirst(string S) {
    stringstream read(S);
    read.get();
    int row; int col;
    read >> row;
    read.get();
    read >> col;

    stringstream answer;
    
    int length, count;
    for (length = 1, count = 26; count < col; count *= 26, ++length)
        col -= count;

    --col;
    count /= 26;

    for (; length > 0; --length, count /= 26) {
        answer << static_cast<char>('A' + col/count);
        col %= count;
    }

    answer << row;
    return answer.str();
}

int main() {
    int N; cin >> N;
    
    for (int i = 0; i < N; ++i) {
        string S; cin >> S;
        
        int type = 1;
        if (S[0] != 'R' || S[1] < '0' || S[1] > '9')
            type = 0;

        if (S.find('C') > S.size())
            type = 0;

        if (type == 0)
            cout << toSecond(S) << "\n";
        else
            cout << toFirst(S) << "\n";
    }
}