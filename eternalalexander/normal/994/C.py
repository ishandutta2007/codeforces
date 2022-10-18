import math

edges1=[]
edges2=[]

def get_distance(pointA, pointB):
    a1, a2 = pointA[0], pointB[0]
    b1, b2 = pointA[1], pointB[1]
    return math.sqrt((a1-a2)**2+(b1-b2)**2)
string=raw_input().split(' ')
for i in range(len(string)):
    string[i]=int(string[i])+200
pts1=[[string[0], string[1]], [string[2], string[3]], [string[4], string[5]], [string[6], string[7]]]
string=raw_input().split(' ')
for i in range(len(string)):
    string[i]=int(string[i])+200
pts2=[[string[0], string[1]], [string[2], string[3]], [string[4], string[5]], [string[6], string[7]]]
for i in range(0, 4):
    edges1.append([pts1[i], pts1[(i+1)%4]])
    edges2.append([pts2[i], pts2[(i+1)%4]])
class Point(object):
    x =0
    y= 0
    def __init__(self, pos=[0, 0]):
        self.x, self.y = pos
        self.pos = pos

class Line(object):
    def __init__(self, p1, p2):
        self.p1 = p1
        self.p2 = p2

def GetLinePara(line):
    line.a =line.p1.y - line.p2.y;
    line.b = line.p2.x - line.p1.x;
    line.c = line.p1.x *line.p2.y - line.p2.x * line.p1.y;


def GetCrossPoint(p1, p2,p3, p4):
    l1 = Line(Point(p1), Point(p2))
    l2 = Line(Point(p3), Point(p4))
    GetLinePara(l1);
    GetLinePara(l2);
    d = l1.a * l2.b - l2.a * l1.b
    if d==0: return False
    return [(l1.b * l2.c - l2.b * l1.c)*1.0 / d, (l1.c * l2.a - l2.c * l1.a)*1.0 / d];
def crossPoint(p1, p2, p3, p4):
    l1 = Line(Point(p1), Point(p2))
    l2 = Line(Point(p3), Point(p4))
    GetLinePara(l1);
    GetLinePara(l2);
    d = l1.a * l2.b - l2.a * l1.b
    if d==0: return False
    p= [(l1.b * l2.c - l2.b * l1.c)*1.0 / d, (l1.c * l2.a - l2.c * l1.a)*1.0 / d]
    if get_distance([(l1.p1.x+l1.p2.x)/2, (l1.p1.y+l1.p2.y)/2], p)>get_distance(l1.p1.pos, l1.p2.pos)/2:
        return False
    if get_distance([(l2.p1.x+l2.p2.x)/2, (l2.p1.y+l2.p2.y)/2], p)>get_distance(l2.p1.pos, l2.p2.pos)/2:
        return False
    return p
def get_area(points):
    value = 0
    n=len(points)
    for i in range(len(points)):
        value += points[i][0]*points[(i+1)%n][1] - points[i][1]*points[(i+1)%n][0]
    return abs(value)/2.0

def IN(x, edges, are):
    tot=0
    if are<0.0001:
        return x==edges[0]
    for i in edges:
        a, b=i
        tot+=get_area([x, a, b])
    if abs(tot-are)<0.0001:
        return True
    return False

def main():
    are1=get_area(pts1)
    are2=get_area(pts2)
    for i in pts1:
        if IN(i, edges2, are2):
            print "YES"
            return
    for i in pts2:
        if IN(i, edges1, are1):
            print "YES"
            return
    for i in edges1:
        for j in edges2:
            a, b=i
            c, d=j
            if crossPoint(a, b, c, d):
                print "YES"
                return
    print "NO"
    return
main()