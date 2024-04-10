//#include <fstream>
#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

//ifstream cin("tema.in");
//ofstream cout("tema.out");

int line[8] = {1, 1, 0, -1, -1, -1, 0, 1};
int column[8] = {0, -1, -1, -1, 0, 1, 1, 1};

bool seen[500][500];

struct Cell {
    int line, column;
    int direction;

    Cell() {}

    Cell(int _line, int _column, int _direction):
        line(_line), column(_column), direction(_direction) {}

    bool operator < (const Cell &other) const {
        if (line != other.line)
            return line < other.line;
        if (column != other.column)
            return column < other.column;
        return direction < other.direction;
    }

    bool operator == (const Cell &other) const {
        if (line == other.line && column == other.column && direction == other.direction)
            return true;
        return false;
    }
};

vector<Cell> cells;

int main() {
    int n;
    cin >> n;
    cells.push_back(Cell(250, 250, 0));
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        vector<Cell> newCells;
        for (auto &cell : cells) {
            int l = cell.line, c = cell.column;
            seen[l][c] = true;
            for (int j = 1; j < x; j++) {
                l += line[cell.direction];
                c += column[cell.direction];
                seen[l][c] = true;
            }
            int first = cell.direction + 1, second = cell.direction - 1;
            if (first == 8)
                first = 0;
            if (second == -1)
                second = 7;
            newCells.push_back(Cell(l + line[first], c + column[first], first));
            newCells.push_back(Cell(l + line[second], c + column[second], second));
        }
        sort(newCells.begin(), newCells.end());
        newCells.resize(unique(newCells.begin(), newCells.end()) - newCells.begin());
        int a = cells.size(), b = newCells.size();
       // if (i == 19)
           // for (auto &it : newCells)
               // cout << it.line << " " << it.column << " " << it.direction << "\n";
        cells.clear();
        cells = newCells;
        newCells.clear();
    }
    int answer = 0;
    for (int i = 0; i < 500; i++)
        for (int j = 0; j < 500; j++)
            if (seen[i][j])
                answer++;
    cout << answer << "\n";
    return 0;
}