from string import ascii_uppercase as letters
import sys

class ColorGrid(object):
    def __init__(self, rows, columns):
        self.grid = [[';' for _ in xrange(columns)] for __ in xrange(rows)]
        self.size = (rows - 1, columns - 1) # maximum index on grid

    def __str__(self):
        return '\n'.join(map(lambda x: ''.join(x), self.grid))

    def setColor(self, coordinates, color):
        assert type(coordinates) == type([])
        assert len(coordinates) == 2
        self.grid[coordinates[0]][coordinates[1]] = color

    def getEmptyOnRow(self, row):
        assert row <= self.size[0]
        rowvals = self.grid[row]
        empty = []
        previous = []
        for val in xrange(len(rowvals)):
            if rowvals[val] == ';':
                previous.append(val)
            else:
                if previous:
                    empty.append(previous)
                    previous = []
        if previous:
            empty.append(previous)
        return empty

    def getNeighbors(self, coordinates):
        neighbors = []
        for i in ((-1, 0), (0, -1), (1, 0), (0, 1)):
            if (0 <= coordinates[0] + i[0] <= self.size[0]) and (0 <= coordinates[1] + i[1] <= self.size[1]):
                color = self.grid[coordinates[0] + i[0]][coordinates[1] + i[1]]
                if color != ';':
                    neighbors.append(color)
        return neighbors
    
    def isFilled(self):
        for row in self.grid:
            for entry in row:
                if entry == ';':
                    return False
        return True

    def fillSquare(self, coordinates, size, color):
        for row in xrange(coordinates[0], coordinates[0] + size):
            for column in xrange(coordinates[1], coordinates[1] + size):
                self.setColor([row, column], color)
        return

    @staticmethod
    def bestColor(badColors):
        return min(filter(lambda x: x not in badColors, letters))


ipt = map(int, sys.stdin.read().split())
grid = ColorGrid(ipt[0], ipt[1])
currentrow = 0

while not grid.isFilled():
    empty = grid.getEmptyOnRow(currentrow)
    for emptygroup in empty:
        neighborslist = [grid.getNeighbors([currentrow, i]) for i in emptygroup]
        bestcolors = map(ColorGrid.bestColor, neighborslist)
        counter = 0
        colorsAreLeft = True
        while colorsAreLeft: # while there still are squares
            size = 0
            color = bestcolors[counter]
            start = emptygroup[counter]
            while True: # find a single square
                neighborslist = [grid.getNeighbors([currentrow, i]) for i in emptygroup]
                bestcolors = map(ColorGrid.bestColor, neighborslist)
                if (bestcolors[counter] == color) and (size < grid.size[0] - currentrow + 1):
                    size += 1
                else:
                    grid.fillSquare([currentrow, start], size, str(color))
                    break
                if counter == len(bestcolors) - 1:
                    grid.fillSquare([currentrow, start], size, str(color))
                    colorsAreLeft = False
                    break
                
                counter += 1
    currentrow += 1

sys.stdout.write(str(grid))