#!/usr/bin/ruby
include Math

a, b = gets.split().map(&:to_i)
x, y, z = gets.split().map(&:to_i)
aa = 2*x + y
bb = 3*z + y
puts [aa-a, 0].max + [bb-b, 0].max